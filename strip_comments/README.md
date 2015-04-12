# strip_comments

## Description

Strip comments and empty lines from files.

## Capabilities
* Detect characters used to introduce comments based on filename
* Detect characters used to introduce comments based on shebang. (Shebangs or those things: #!/bin/bash)
* Reduce adjacent empty and comment-only lines to one line or optionally remove them completely.
* Print line numbers
* Tons of options for flexibility. Use ***strip_comments --help*** to learn more.

## Sample
Here is a excerpt from a TOR config file I found on one of my machines. It's pretty hard to find the actual configuration part.
```
## Required: what port to advertise for incoming Tor connections.
# ORPort 443
## If you want to listen on a port other than the one advertised in
## ORPort (e.g. to advertise 443 but bind to 9090), you can do it as
## follows.  You'll need to do ipchains or other port forwarding
## yourself to make this work.
ORPort 443 NoListen
#ORPort [2a01:4f8:101:10ab:6ca1:a8f6:cd6a:6255]:443 NoListen
ORPort 9001 NoAdvertise
ORPort [2a01:4f8:101:10ab:6ca1:a8f6:cd6a:6255]:9001

## The IP address or full DNS name for incoming connections to your
## relay. Leave commented out and Tor will guess.
Address tor-exit1.arbitrary.ch

## A handle for your relay, so people don't have to refer to it by key.
Nickname arbitrary1

## Use these to restrict the maximum traffic per day, week, or month.
## Note that this threshold applies separately to sent and received bytes,
## not to their sum: setting "4 GB" may allow up to 8 GB total before
## hibernating.
##
## Set a maximum of 4 gigabytes each way per period.
#AccountingMax 4 GB
## Each period starts daily at midnight (AccountingMax is per day)
#AccountingStart day 00:00
## Each period starts on the 3rd of the month at 15:00 (AccountingMax
## is per month)
#AccountingStart month 3 15:00

## Contact info to be published in the directory, so we can contact you
## if your relay is misconfigured or something else goes wrong. Google
## indexes this, so spammers might also collect it.
#ContactInfo Random Person <nobody AT example dot com>
## You might also include your PGP or GPG fingerprint if you have one:
ContactInfo 4B45 672A E4D1 5C01 E663 E826 3E51 19FB 0B2C 1DFB Peter Gerber <peter@tschoerbi.ch>
```

Now let's see what happens if we pass the file to strip_comments using the following command: **strip_comments -n torrc**. It's a little easier to read, isn't it? The line number are often pretty useful too.

```
       7 | ORPort 443 NoListen
       9 | ORPort 9001 NoAdvertise
      10 | ORPort [2a01:4f8:101:10ab:6ca1:a8f6:cd6a:6255]:9001
         | 
      14 | Address tor-exit1.arbitrary.ch
         | 
      17 | Nickname arbitrary1
         | 
      37 | ContactInfo 4B45 672A E4D1 5C01 E663 E826 3E51 19FB 0B2C 1DFB Peter Gerber <peter@tschoerbi.ch>
```

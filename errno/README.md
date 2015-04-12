# errno

## Description

Print error description for given errno

## How it works


```bash
$ errno 12
 12 --> Cannot allocate memory

$ errno 2 4
  2 --> No such file or directory
  4 --> Interrupted system call

$ errno 1-3 12-14
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

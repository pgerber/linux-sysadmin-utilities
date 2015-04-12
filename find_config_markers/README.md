# find_config_markers

## Description

Find sections within configuration files that are enclosed with special markers

## Capabilities
* Find section of files that were marked previously.
* Scan through directories recursively.
* The markers can be nested. Can't remember why I implemented that. It just seems so useless. But it works.
* To find out about more options execute **find_config_markers --help**

## Basics
Often you'll change some configuration option and then, when you want to change it again, you can't find it anymore. To avoid exactly that, I created this script.

To show you how it works, let's look at an openssh server configuration I adjusted a while ago. Below you see a shortened version of such the file.
As you can see there are two sections marked using **# -- mark begin --** and **# -- mark end --**.

```
# Change to yes to enable challenge-response passwords (beware issues with
# some PAM modules and threads)
ChallengeResponseAuthentication no

# Change to no to disable tunnelled clear text passwords
# -- mark begin --
PasswordAuthentication no
# -- mark end --

# Kerberos options
#KerberosAuthentication no

# If you just want the PAM account and session checks to run without
# PAM authentication, then enable this but set PasswordAuthentication
# and ChallengeResponseAuthentication to 'no'.
UsePAM yes


# -- mark begin --
Subsystem sftp internal-sftp

Match Group srv-backup
       ChrootDirectory /sftp/%u
       AuthorizedKeysFile /home/%u/.ssh/authorized_keys
       X11Forwarding no
       AllowTcpForwarding no
       ForceCommand internal-sftp
# -- mark end --

```

Now we use **find_config_markers /etc/ssh/sshd_config** to just look at the part enclosed by the markers. Here's the output:

```
      52 | PasswordAuthentication no
         |
      93 | Subsystem sftp internal-sftp
      94 |
      95 | Match Group srv-backup
      96 |        ChrootDirectory /sftp/%u
      97 |        AuthorizedKeysFile /home/%u/.ssh/authorized_keys
      98 |        X11Forwarding no
      99 |        AllowTcpForwarding no
     100 |        ForceCommand internal-sftp
```

As mentioned before, it can be used recursively. Here is a partial output of **find_config_markers -qr /etc** executed on one of my machines:
```
File: /etc/tsocks.conf
      43 | server = 127.0.0.1
      49 | server_port = 2222

File: /etc/nsswitch.conf
      12 | #hosts:          files mdns4_minimal [NOTFOUND=return] dns mdns4
      13 | hosts:          files dns

File: /etc/fstab
      31 | proc            /proc           proc    defaults,hidepid=2,gid=1000,nodev,nosuid,noexec,relatime        0       0
      32 | none            /home/tmp       tmpfs   uid=peter,gid=peter,mode=750,nr_inodes=10000000                 0       0

File: /etc/sysctl.d/own.conf
       2 | ### disable ipv6 autoconfiguration ###
       3 | #net.ipv6.conf.all.autoconf = 0
       4 | #net.ipv6.conf.default.autoconf = 0

File: /etc/default/grub
      10 | GRUB_CMDLINE_LINUX_DEFAULT="quiet audit=1 init=/bin/systemd"

File: /etc/modprobe.d/rfkill.conf
       2 | options rfkill master_switch_mode=2
```

## Alternative Markers
Alternatively to the syntax used for the marker so far, the following syntax may be used too:
```
# -- mark begin --
// -- mark begin --
; -- mark begin --
/* -- mark begin -- */
#--mark begin--
    # -- mark begin -- Whatever is right of the -- is ignored. Spaces and tabs on the left are just fine too.
```

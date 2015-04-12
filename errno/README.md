# errno

## Description

Print error description for given errno

## How it works


```bash
# Description of just one errno error code
$ errno 12
 12 --> Cannot allocate memory

# Description of multiple error codes
$ errno 2 4
  2 --> No such file or directory
  4 --> Interrupted system call

# Descriptions for a ranges
$ errno 1-3 12-14
  1 --> Operation not permitted
  2 --> No such file or directory
  3 --> No such process
 12 --> Cannot allocate memory
 13 --> Permission denied
 14 --> Bad address

# Error position indication
$ errno 1-4 1b-12
error: Argument 2: non-digit characters detected
error:   1b-12
error:    ^
```

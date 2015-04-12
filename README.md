# linux-sysadmin-utilities

Hello there, here you'll find some more or less useful stuff I've written over the years.

## What's to Find Here
### strip_comments
A small Python program to display files without lines that are completely commented out. It also has some more advanced features like displaying line numbers. Or Detecting sequences of intermixed empty lines and comments that it just reduces to but one single line for brevity.

It has proven to be quite useful in order to remove comments from configuration files. Many of them consist mainly of empty lines and comment. Oftentimes, seeing the actual config and nothing else is all you want.

See readme in strip_comments directory for details.

### find_config_markers
Python script that allows to find and print specially marked section in config files. Sections within configuration files can be marked using very simple markers.

I use it to mark sections in config files that I have modified. With this script I can easily find them again. Even recursive searches through directories are possible.

See readme in find_config_markers directory for details.
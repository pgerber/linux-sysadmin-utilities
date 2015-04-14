# linux-sysadmin-utilities

Hello there, here you'll find some more or less useful stuff I've written over the years.

## What's to be Found Here

### cd_enhanced
Everybody knows how cumbersome it can be to use **cd** to change directories. Especially, when you need to change to ones that are nested deeply within the filesystem hierarchy.
To help with this, I created a script or rather a set of bash function that provide you with bookmark functionality.

See readme in [cd_enhanced directory](cd_enhanced) for details

### errno
Simple C program that shows you the error messages associated with errno error numbers.

See readme in [errno directory](errno) for details.

### find_config_markers
Python script that allows to find and print specially marked section in config files. Sections within configuration files can be marked using very simple markers.

I use it to mark sections in config files that I have modified. With this script I can easily find them again. Even recursive searches through directories are possible.

See readme in [find_config_markers directory](find_config_markers) for details.

### strip_comments
A small Python program to display files without all the lines that are commented out. It also has some more advanced features like displaying line numbers. Or Detecting sequences of intermixed empty lines and comments that it just reduces to but one single line for brevity.

It has proven to be quite useful in order to remove comments from configuration files. Many of them consist mainly of empty lines and comment. Oftentimes, seeing the actual config and nothing else is all you want.

See readme in [strip_comments directory](strip_comments) for details.

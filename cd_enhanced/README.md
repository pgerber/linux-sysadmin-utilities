# errno

## Description

Everybody knows how cumbersome it can be to use ```cd``` to change directories. Especially, when you need to change to ones that are nested deeply within the filesystem hierarchy.
To help with this, I created a script or rather a set of bash function that provide you with bookmark functionality.

## Installation Process

In order for this to work you'll need to add the following to the **end** of your ~/.bashrc file.

You, of course, need to adjust the path should you place the script somewhere else.

```bash
if [ -f "$HOME/scripts/cd_extended" ]; then
     . "$HOME/scripts/cd_extended"
fi
```

## Functions Provided by cd_enhanced

### cds
Syntax: ```cds ENTRY_NAME [PATH]```

Add a bookmark called ENTRY_NAME that points to PATH. If PATH is not given, it will point to the working directory.

### cdr
Syntax: ```cdr [ENTRY_NAME]```

Jump to path associated with the bookmark ENTRY_NAME. If ENTRY_NAME is omitted, the last used bookmark is used instead.

### cdpath
Syntax: ```cdpath [ENTRY_NAME]```

Print the path associated with ENTRY_NAME. If ENTRY_NAME is omitted, the last used bookmark is used instead.

### cdremove
Syntax: ```cdremove ENTRY_NAME...```

Remove the bookmarks named ENTRY_NAME.

### cdlist
Syntax: ```cdlist```

List the currently defined bookmarks.

### cdexport
Syntax: ```cdexport```

Export bookmarks in a format that can be used for importing with ```cdimport``` later on. Export data is printed to stdout.

### cdimport
Syntax: ```cdimport [INPUT_FILE]```

Reimport bookmarks previously exported by ```cdexport```. Without an INPUT_FILE given, input is read from stdin.

## How it works

```bash
# add bookmark for the shell's working directory
$ cd ~/src/linux-utilities
$ cds git

# add bookmark for a specific path
$ cds v28 ~/src/nice_v2.8

# change to directory
$ cd /
$ cdr git
$ pwd
/home/peter/src/linux-utilities

# change directly to a subdirectory (hint: use tab for auto-completion)
$ cd /
$ cdr git/cd_enhanced
$ pwd
/home/peter/src/linux-utilities/cd_enhanced

# integration in commands using cdpath
$ cp -r "$(cdpath v28/subdir) /home/peter/target"

# list the existing bookmarks
$ cdlist
+---------------------------------------------------------------------+
|                      Available entries                              |
+---------------------------------------------------------------------+
        git              -> *  /home/peter/src/linux-utilities
        v28              -> #  /home/peter/src/nice_v2.8
-----------------------------------------------------------------------
Number of entries: 2

* -> Last used entry.
# -> Target directory does not exist.
```

# Chapter 1 Notes
## `printf()` conversion characters

| Character | Description                                   |
| ---       | -----------                                   |
| c         | as a character                                |
| d         | as a decimal integer                          |
| e         | as a floating-point number in sci notation    |
| f         | as a floating-point number                    |
| g         | in the e-format or f-format (shorter one)     |
| s         | as a string                                   |

### Format
* **`%3s`**

## `scanf()` conversion characters
| Character | Description                                   |
| ---       | -----------                                   |
| c         | character                                     |
| d         | decimal integer                               |
| f         | floating-point number (float)                 |
| s         | string                                        |

**`scanf()`** returns as an int the number of successful conversions formed.
**`exit()`** when it is invoked, houskeeping tasks are performed the the program terminates.

**`0 = normal exit`**
**`nonzero = otherwise`**

`min = max = x`
: the `=` operator is right associative so this is the same as `max = x` and `min = x`.

Pipe data from data into program running_sum. 
: `running_sum < data`

This runs the program with infile input, and pipes results to outfile.
: `program < infile > outfile`
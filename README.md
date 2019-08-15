# convert
Base conversion program

This program converts data from one base to another.
There are upto 62 possible bases depending on the options provided.
The program is completely command-line and argument-based.

### Usage
The usage of the program can be found by supplying `--help` or `-h` option.
The help message is as follows:
```
Usage: convert [baseOptions] [-P|--no-pad] data
Convert data from one base to another.
baseOptions:
  -f <base>, --from=<base>  convert the data from given base to base 10
  -t <base>, --to=<base>    convert the data from base 10 to given base
  --<base1>to<base2>        convert data from & to predefined bases
NOTE: If --<base1>to<base2> option is not set, -t or -f or both HAVE to be set.
      If either is omitted, it is taken to be 10.

Predefined bases:
  bin    binary; base 2 (digits: 0-1)
  dec    decimal; base 10 (digits: 0-9)
  hex    hexadecimal; base 16 (digits: 0-9,A-F/a-f)
  oct    octal; base 8 (digits: 1-8)

Other options:
  -P, --no-pad  do NOT pad the output, default setting pads output
  -h, --help    show this help message

e.g. convert --hex2bin E2F4
       converts E2F4 to binary
```

### Contributing
Contributions to this program are welcome in the form of pull requests.
Contributers are requested to group the commits as individual units of features/fixes etc.
The contribution will be acted upon within a week of pull request.
All the comments/replies to comments will also be replied to within a week.

Feel free to suggest anything and star this repository ;).

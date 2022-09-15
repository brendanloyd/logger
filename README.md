This program implements a message logger that holds messages in a queue.

To call this program use the format:

./driver [-h] [-t] [filename.txt]

If called with the [-t] option, getopt will require a following argument.

An example call would be:

./driver -t 5 test.txt

In the event that a filename is not provided, the program will log messages to the messages.log file.

More example program calls:

./driver -h

./driver test.txt

./driver -h -t 5

./driver -h -t 5 test.txt

Note: when called with the -h option, the program will exit following the help message.

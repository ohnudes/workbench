#   SYZEOF(TYPE)
Test in order to understand the different size values for
different types.

    -   sizeof char / int / double  -   [[sizeof.c]]
    -   address for char / int / double - [[address.c]]

# Memory order

The following test are done in order to comprehend how 
memory is allocated and ordered:

    -   Array   -   [[arraymem.c]]
    -   Union   -   [[unionmem.c]]
    -   Struct  -   [[structmem.c]]
        \-> Struct addresses **padding** and **alignment**

# Alignment
Conceptually, given int i: its 1 byte, followed by 3 other bytes
However, on actual hardware, data types are understood based
on computer words, i.e. 64bits. It has to do with the bus that
carries data which can process definitives amounts of sizes, not more
nor less.
In case for less, it means that not all the word space is used.
In case of more, it means it has to do multiple reads and some
bit manipulation. 
In conclusion, a 32bit int with memory offset, can be more expensive
for the machine, than a regular 64bit sitting at the right offset.

    -   Struct  -   [[structmem.c]]   
    -   Align   -   [[alignof.c]]

Variables at memory locations that match what the hardware can handle
or is programed to infer, the memory is then said to be *aligned*,
and *memory alignment* **can be critical**.
For more info, check macro: *alignof()*



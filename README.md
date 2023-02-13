# Data-Compression-Data-Structures-C-

This project's purpose is to build a data compression method. That is, we want to convey the same
information in a smaller amount of space given particular data. We'll be concentrating on
compressing text files for this project, so we'll need to first learn how computers internally
represent text.
Computers save information as a series of bytes. A byte is an eight-bit value that ranges from 0 to
255. We need a technique to assign each English letter, punctuation symbol, special character,
and other characters to an eight-bit(a value from 0 to 255) sequence in order to represent English
text. The ASCII encoding, as stated in the table below, is responsible for this mapping. Notice
that ASCII only uses 128 out of the 256 possible values that a byte can store.

A string of symbols aadbaaca would be encoded as 0011100001010. This would yield
compression considering the original requires 8 bits per symbol. So 64 bits have been reduced to
13 bits. The reason we get compression is that the symbol “a” occurs quite frequently in the
original and the Huffman code uses just one bit to encode it. There is a simple process to
decoding a Huffman code. Start at the root of the tree. If you are at a leaf output the symbol.
Otherwise read a bit and go left if is 0 and go right if is 1 and continue in that manner until
reaching a leaf. An optimal Huffman code is one that produces the shortest code given
frequencies for the symbols.

Task No. 1:
Build simple Tree based Huffman coding scheme and show the results.
Task No. 2:
The second task in this project is to use predefined priority queues to build an optimal Huffman
tree. Your priority queue will maintain the current set of trees ordered by their frequencies. One
challenge is to efficiently traverse the optimal Huffman tree to generate the code to be printed
out.

Again we are not too concerned with the user interface because we are working with the data
structures. The program requests a text file name, then computes the optimal Huffman code and
prints it. The compression ratio is then printed.
> Please enter a text file name:
foo.txt
> The optimal Huffman code is:
> a 0
> b 100
> c 101
> d 11
> The compression ratio is:
> 4.92

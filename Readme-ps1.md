# PS1: LFSR / PhotoMagic

## Contact
Name: Wilson Van

Section: 202

Time to Complete: 5hr


## Description
Added on to the first part of ps1. This part of PS1 made a function called transform which takes an image and a FibLSFR object and encrypts the image based on the pseudo random seed from the FibLSFR to make it look like a bunch of random pixels. When an encrypted image is put through the transform function with the correct seed the image is decrypted back to the original.

### Features
I made the transform function according to the given instructions. I then used the given code in the instructions to make 2 windows, adjusting the size accordingly. I then used 4 different sprites and textures which were made with the given inputs which were used to make images. After the second texture and sprite were made I used them to create a file according to the arguments given in a command line to save the image.

### Issues
Everything works as intended.

### Tests
The first test uses the step function on multiple registers with calculated outcomes.
The second test uses a sequence of generate functions to match the given example from the instructions pdf.
The third test uses the sequence of steps from the instructions pdf to see if the generate function returns the correct result.
The fourth test makes sure only the tap bits are used to calculate the right most bit.
The fifth test makes sure the register is printed.
The last test creates a single pixel image which goes through the transform function and then changes the color of the pixel accordingly.

### Extra Credit
I didn't do anything special.

## Acknowledgements
I collaborated with my roommate Owen and Gia who are taking the same class.

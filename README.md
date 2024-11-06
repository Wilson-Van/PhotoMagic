#Project: Image Encryptor and Decryptor

# Contact:

Name: Wilson Van

## Description

This is one of the first coding assignments for Computing 4 at Umass Lowell. This assignment was split into two parts. In the first part I create a LFSR (Linear Feedback Shift Register) Class which was a class that simulated a 16 bit register which uses the most significant bit, third most significant bit, fourth most significant bit and the sixth most significant bit to calculate the least significant bit of the bit string after it was left shifted once. This was done by doing 3 consecutive xor calculations on each of the named bits to determine if the least significant bit should have been turned on or off  (1 or 0 respectively). This was then added upon in the second part of this assignment by applying it to a PhotoMagic namespace to encrypt and decrypt images. In the PhotoMagic namespace I created a transform method which took an image and a 16 bit string as parameters. In this method the height and length of the image in pixels was taken and looped through to get the rgb value for each pixel. I then used the 16 bit string to generate a psuedo random 8 bit number. That 8 bit number would be xor'ed with the red value of the pixel. The 16 bit string would be shifted at this point after generating the 8 bit number. This process would be repeated for the green and blue values before replacing the pixel of the original image. This process would then be repeated for the entirety of the whole image encrypting the image to look like a bunch of random pixels. To decrypt the image the encrypted image would be passed through as a parameter of the transform method with the original 16 bit string.

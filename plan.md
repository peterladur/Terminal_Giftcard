**Plan**


1. The ASCII art should be in # in a .txt file.
2. The file is read line by line and added to an array of arrays of fixed length
3. We grab the boundary of the image and then rotate that boundary in z coordinates.
4. Then go through the char line by line and see if it should be inside the boundary
    If a char is meant to be inside, we can display it
    If a char is meant to be outside we can ommit it
    We can modify the chars based on the z value (for example changing their colours)
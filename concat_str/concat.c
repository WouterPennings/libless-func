char *concat(char s1[], char s2[]) {
    int i, j = 0;
    while(s1[++i] != 0); // I gets length of s1 

    // Appends all characters one by one to s1
    for (j = 0; s2[j] != '\0'; i++, j++) {
        s1[i] = s2[j];
    }   

    // Appends NULL to and of string
    s1[i] = '\0';
    return s1;
}

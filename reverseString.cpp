void reverseString(char* s, int sSize){
    if (s == NULL || sSize == 0)    return;
    for (int i = 0, j = sSize - 1; i < (sSize / 2); ++i, --j)
    {
        char tmp = s[i];
        s[i] = s[j];
        s[j] = tmp;
    }
}

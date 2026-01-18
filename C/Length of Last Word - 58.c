int lengthOfLastWord(char* s) {
    int len = strlen(s), count = 0;
    for (int i = len - 1; i >= 0; i--) {
        if (s[i] != ' ')
            count++;
        else if (count > 0)
            break;
    }
    return count;
}

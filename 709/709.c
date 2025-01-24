char *toLowerCase(char *s)
{
    int i;
    for (i = 0; i < strlen(s); i++)
    {
        s[i] = tolower(s[i]);
    }
    return s;
}
char * defangIPaddr(char * address)
{
    char* p = address;
	char* buff = (char*)malloc(strlen(address) + 7);
	char* q = buff;
	while (*p != '\0')
	{
		if (*p == '.')
		{
			*q = '[';
			*(q + 1) = '.';
			*(q + 2) = ']';
			q += 3;
			p++;
		}
		else
			*(q++) = *(p++);
	}
	*q = '\0';
	return buff;
	free(buff);
}

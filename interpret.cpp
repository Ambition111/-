/*
ʾ�� 1��

���룺command = "G()(al)"
�����"Goal"
���ͣ�Goal ��������������Ĳ���������ʾ��
G -> G
() -> o
(al) -> al
������ӵõ��Ľ���� "Goal"

ʾ�� 2��

���룺command = "G()()()()(al)"
�����"Gooooal"
*/ 

char * interpret(char * command){
    char* buff = (char*)malloc(sizeof(char) * (strlen(command) + 1));
    if (buff == NULL)   return NULL;
    int i = 0;
    for (int j = 0; command[j] != '\0'; )
    {
        if (command[j] == '(' && command[j + 1] ==')')
        {
            buff[i++] = 'o';
            j += 2;
            continue;
        }
        if (command[j + 1] != '\0' && (command[j] == '(' && command[j + 1]) || command[j] == ')')
            ++j;
        else
            buff[i++] = command[j++];
    }
    buff[i] = '\0';
    return buff;
    free(buff);
}

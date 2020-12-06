/*
示例 1：

输入：command = "G()(al)"
输出："Goal"
解释：Goal 解析器解释命令的步骤如下所示：
G -> G
() -> o
(al) -> al
最后连接得到的结果是 "Goal"

示例 2：

输入：command = "G()()()()(al)"
输出："Gooooal"
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

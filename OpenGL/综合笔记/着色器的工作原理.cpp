




顶点着色器 的使用：Vertex Shader


const char *vertexShaderSource = "#version 330 core\n"
    "layout (location = 0) in vec3 aPos;\n"
    "void main()\n"
    "{\n"
    "   gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
    "}\0";


//创建一个着色器对象，注意还是用ID来引用的
unsigned int vertexShader;
vertexShader = glCreateShader(GL_VERTEX_SHADER);

//着色器源码附加到着色器对象上，然后编译它：
glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);//配置源
glCompileShader(vertexShader);//编译它



//检测在调用glCompileShader后编译是否成功

int  success;
char infoLog[512];
glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);


if(!success)
{
    glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
    std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;
} 



片段着色器 的使用：Fragment Shader


unsigned int fragmentShader;
fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
glCompileShader(fragmentShader);


其他部分相似




着色器程序
	多个着色器合并之后并最终链接完成的版本，



创建一个程序对象
unsigned int shaderProgram;
shaderProgram = glCreateProgram();



把之前编译的着色器附加到程序对象上，然后用glLinkProgram链接它们：

glAttachShader(shaderProgram, vertexShader);
glAttachShader(shaderProgram, fragmentShader);
glLinkProgram(shaderProgram);


glUseProgram(shaderProgram);


在把着色器对象链接到程序对象以后，记得删除着色器对象，我们不再需要它们了

glDeleteShader(vertexShader);
glDeleteShader(fragmentShader);
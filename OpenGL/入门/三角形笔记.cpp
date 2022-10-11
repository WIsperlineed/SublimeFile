


//hello triangle



float vertices[] = {
    -0.5f, -0.5f, 0.0f,
     0.5f, -0.5f, 0.0f,
     0.0f,  0.5f, 0.0f
};



##顶点着色器##

它会在GPU上创建内存用于储存我们的顶点数据，还要配置OpenGL如何解释这些内存，并且指定其如何发送给显卡。顶点着色器接着会处理我们在内存中指定数量的顶点。


VBO管理内存


unsigned int VBO;
glGenBuffers(1,&VBO);//生成一个VBO对象

glBindBuffer(GL_ARRAY_BUFFER, VBO);  //新创建的缓冲绑定到GL_ARRAY_BUFFER目标上
	//GL_ARRAY_BUFFER是缓冲类型，顶点缓冲对象的缓冲类型

glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);//glBufferData函数，它会把之前定义的顶点数据复制到缓冲的内存中：







##Vertex Shader:顶点着色器##


#version 330 core//版本声明，核心模式
layout (location = 0) in vec3 aPos;//layout (location = 0)设定了输入变量的位置值(Location)

void main()
{
    gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);
}




//着色器编译：

const char *vertexShaderSource = "#version 330 core\n"
    "layout (location = 0) in vec3 aPos;\n"
    "void main()\n"
    "{\n"
    "   gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
    "}\0";

//动态编译它的源代码

unsigned int vertexShader;
vertexShader = glCreateShader(GL_VERTEX_SHADER);//ID引用创建shader



glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);//着色器源码附加到着色器对象上，然后编译它,参数2指定了传递的源码字符串数量
glCompileShader(vertexShader);


//检测在调用glCompileShader后编译是否成功



int  success;
char infoLog[512];
glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);


if(!success)
{
    glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
    std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;
}



##片段着色器##，Fragment Shader: {片段着色器所做的是计算像素最后的颜色输出}

//过程同顶点着色器相同

unsigned int fragmentShader;
fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
glCompileShader(fragmentShader);




##着色器程序##

还需要将 
{两个着色器对象链接到一个用来渲染的着色器程序(Shader Program)中。}


unsigned int shaderProgram;
shaderProgram = glCreateProgram();//创建一个程序，并返回新创建程序对象的ID引用

glAttachShader(shaderProgram, vertexShader);
glAttachShader(shaderProgram, fragmentShader);
glLinkProgram(shaderProgram);



glUseProgram(shaderProgram);//在glUseProgram函数调用之后，每个着色器调用和渲染调用都会使用这个程序对象（也就是之前写的着色器)了


glDeleteShader(vertexShader);
glDeleteShader(fragmentShader);//着色器对象链接到程序对象以后，记得删除着色器对象



glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);//
glEnableVertexAttribArray(0);//以顶点属性位置值作为参数，启用顶点属性


//指定Opengl如何解释顶点数据，

glVertexAttribPointer()
参数1：顶点属性的位置值设置为0
参数2：顶点属性的大小，vec3,三个
参数3：数据类型，GL_FLOAT
参数4：是否希望数据被标准化，为GL_TRUE则会映射到标准空间中和
参数5：步长，每个顶点数据占多少空间
参数6：void*之后再解释

##EBO索引缓冲对象##

float vertices[] = {
    0.5f, 0.5f, 0.0f,   // 右上角
    0.5f, -0.5f, 0.0f,  // 右下角
    -0.5f, -0.5f, 0.0f, // 左下角
    -0.5f, 0.5f, 0.0f   // 左上角
};

unsigned int indices[] = {
    // 注意索引从0开始! 
    // 此例的索引(0,1,2,3)就是顶点数组vertices的下标，
    // 这样可以由下标代表顶点组合成矩形

    0, 1, 3, // 第一个三角形
    1, 2, 3  // 第二个三角形
};


unsigned int EBO;
glGenBuffers(1, &EBO);

glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);


glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);






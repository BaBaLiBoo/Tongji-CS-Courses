CXX = g++                # 使用的编译器
CXXFLAGS = -std=c++11 -O2 # 编译选项，启用 C++11 标准并优化代码
TARGET = huffman      # 输出的可执行文件名
SRC = main.cpp             # 源代码文件列表

# 默认规则：编译并链接

$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) $(SRC) -o $(TARGET) # 编译命令

# 清理规则：删除生成的可执行文件

clean:
	rm -f $(TARGET)   # 删除编译后的目标文件 

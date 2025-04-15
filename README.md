

#### .vscode/settings.json
- 包含格式化、cmake配置
```json
{
    "C_Cpp.clang_format_style": "{ BasedOnStyle: Google, IndentWidth: 4}",
    "cmake.buildTarget": "${command:cmake.activeBuildTarget}",
    "cmake.configureOnOpen": true,
    "cmake.buildOnSave": false
}
```

#### 脚本设置
- 添加到环境变量
```bash
echo 'alias lc="/path/to/python /path/to/lc.py"' >> ~/.bashrc
source ~/.bashrc
```
- 修改lc.py：配置新建源文件的初始模板、源文件默认存放的目录、build的目录、注释掉一些代码以增删功能
- 使用
```perl
lc new 274
lc build 274
lc run 274
lc all 274
```

我一般使用的功能：
```
lc 274
```
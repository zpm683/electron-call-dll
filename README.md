# electron-call-dll

## we know use the node-ffi to call dll is easly, 
## but in >electron5 [node.js 12+], node-ffi cannt work (node-ffi used node.js 8)
## so we need to use the addon to call dll.

## i used this (nan api)[https://github.com/nodejs/nan api] to call the add.dll.

## add.dll src

```
#include "stdafx.h"
extern "C" _declspec(dllexport) int Add(int x, int y)//申明函数为导出函数
{
	int result = x + y;
	return result;
}
```

## how to start?
- npm install --global windows-build-tools
- npm install
- npm run rebuild
- npm run start

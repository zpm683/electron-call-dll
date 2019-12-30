# electron-call-dll

## why used addon? not ffi?
we know use the node-ffi to call dll is easly
but in >electron5 [node.js 12+], node-ffi cannt working well  (because node-ffi used node.js 8)
so we need to use the addon to call dll.

## i used this [node-addon-api](https://github.com/nodejs/node-addon-api) to call the add.dll.
### [other node-addon-examples](https://github.com/nodejs/node-addon-examples)
## add.dll src

```
#include "stdafx.h"
extern "C" _declspec(dllexport) int Add(int x, int y)
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

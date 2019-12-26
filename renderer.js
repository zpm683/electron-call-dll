// This file is required by the index.html file and will
// be executed in the renderer process for that window.
// All of the Node.js APIs are available in this process.
const demo = require('./build/Release/demo.node')

document.write("6+6= "+ demo.add());

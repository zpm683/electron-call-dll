// This file is required by the index.html file and will
// be executed in the renderer process for that window.
// All of the Node.js APIs are available in this process.

const addon = require('bindings')('addon.node')
document.write("1+2= "+ addon.add(1,2));

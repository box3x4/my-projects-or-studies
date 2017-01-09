var express = require('express');
var app = express();

app.use(express.static(process.argv[3] || path.join(__dirname, 'public'))).listen(process.argv[2]);
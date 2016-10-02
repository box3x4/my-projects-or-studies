var express = require('express');
var router = express.Router();

var index = require('./index');
var add = require('./add');
var remove = require('./remove');
var view = require('./view');
var edit = require('./edit');

router.get('/', index.get);
router.get('/add', add.get);
router.post('/add', add.post);
router.get('/remove/:id', remove.get);
router.get('/view/:id', view.get);
router.get('/edit/:id', edit.get);
router.post('/edit', edit.post);

module.exports = router;

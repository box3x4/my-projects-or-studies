var express = require('express'),
  app = express(),
  engines = require('consolidate'),
  bodyParser = require('body-parser'),
  MongoClient = require('mongodb').MongoClient,
  assert = require('assert');

app.engine('html', engines.nunjucks);
app.set('view engine', 'html');
app.set('views', __dirname + '/views');
app.use(bodyParser.urlencoded({ extended: true }));

MongoClient.connect('mongodb://localhost:27017/imdb_movies', function(err, db) {

  assert.equal(null, err);
  console.log('successfully connected to the db');

  app.get('/', function(req, res) {
    res.render('movieSend');
  });

  app.post('/movie_input', function(req, res, next) {

    var movie_title = req.body.title,
      movie_year = req.body.year,
      movie_imdb = req.body.imdb;

      if(movie_title === '')
        res.render('error_handler');
      else if(movie_year === '')
        res.render('error_handler');
      else if(movie_imdb === '')
        res.render('error_handler');
      else {
        db.collection('movies').insertOne( { 'title':movie_title, 'year':movie_year, 'imdb':movie_imdb});
        console.log('document inserted into db');

        res.render('movieSend');
      }

  });

  app.get('/back', function(req, res) {
    res.redirect('movieSend');
  });

});

app.listen('3000', function() {
  console.log('app listen on port 3000');
});

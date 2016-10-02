var mongodb = require('mongodb');

var connection = function(callback) {

  mongodb.MongoClient.connect('mongodb://localhost:27017/books', function(err, db) {

    if (err) {

      callback(err,null);
    } else {

      callback(null,db);
    }
  });
};

module.exports.connection = connection;
module.exports.ObjectID = mongodb.ObjectID;

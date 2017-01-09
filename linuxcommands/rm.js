var fs = require('fs');

switch(process.argv[2]){

	case '-d':
		fs.rmdir(process.argv[3], function(err){

			if(err){
				return console.error(err);
			}
		});

		break;

	default:
		fs.unlink(process.argv[3], function(err){

			if(err){
				return console.error(err);
			}
		});
}

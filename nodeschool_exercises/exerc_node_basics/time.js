var net = require('net');

net.createServer(function(socket){

		var date = new Date();

		var year = date.getFullYear();

		var month = ' ';
		if(date.getMonth()+1 < 10)
			month = '0' + (date.getMonth()+1);
		else
			month = date.getMonth()+1;

		var day = ' ';
		if(date.getDate()< 10)
			day = '0' + date.getDate();
		else
			day = date.getDate();


		var hours = ' ';
		if(date.getHours()<10)
			hours = '0'+date.getHours();
		else
			hours = date.getHours();

		var	min = date.getMinutes();
		if(date.getMinutes()<10)
			min = '0'+date.getMinutes();
		else
			min = date.getMinutes();

		var data = year + '-'+month+'-'+day+' '+hours+':'+min+'\n';

		socket.write(data);

		socket.end();

}).listen(process.argv[2]);
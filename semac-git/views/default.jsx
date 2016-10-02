var React = require('react');

var DefaultLayout = React.createClass({
  render: function() {
    return (
      <html>
        <head>
          <meta charset="utf-8" />
          <meta http-equiv="X-UA-Compatible" content="IE=edge" />
          <meta name="viewport" content="width=device-width, initial-scale=1" />
          <title>{this.props.title}</title>
          <link rel="stylesheet" href="/css/bootstrap.min.css"></link>
          <script src="https://use.fontawesome.com/ba59ad11e6.js"></script>
        </head>
        <body>
          <div className="container">
            <div className="jumbotron">
              <h1><strong>Intro to mongoDB: concepts and practices</strong></h1>
            </div>
            {this.props.children}
          </div>
          <script src="/js/jquery.min.js"></script>
          <script src="/js/bootstrap.min.js"></script>
        </body>
      </html>
    );
  }
});

module.exports = DefaultLayout;

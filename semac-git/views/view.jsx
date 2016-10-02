var React = require('react');

var DefaultLayout = require('./default');

var ViewLayout = React.createClass({

  render: function() {

    return (
      <DefaultLayout title="teste react">
        <div className="col-md-12">
          <div className="row">
            <div className="well">
              {
                this.props.book.map(function(book, i) {
                  return (
                    <div>
                      <legend><h2>{book.nome}</h2></legend>
                      <strong>Nome do livro</strong>   {book.nome} <br />
                      <strong>Nome do autor</strong>   {book.autor} <br />
                      <strong>Nome da editora</strong>   {book.editora} <br />
                      <strong>Preco do livro</strong>   {book.preco} <br />
                      <hr />
                      <a href="/"><button type="button" className="btn btn-default">Voltar</button></a>
                    </div>
                  );
                })
              }
            </div>
          </div>
        </div>
      </DefaultLayout>
    );
  }
});

module.exports = ViewLayout;

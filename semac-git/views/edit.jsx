var React = require('react');

var DefaultLayout = require('./default');

var EditLayout = React.createClass({

  render: function() {

    return (
      <DefaultLayout>
        <div className="col-md-12">
          <div className="row">
            <div className="well">
              <form method="post" className="form-horizontal" action="/edit">
                {
                  this.props.book.map(function(book, i) {
                    return (
                      <fieldset>
                        <legend>Editar livro: {book.nome}</legend>
                        <div className="form-group">
                          <label for="nome" className="col-lg-2 control-label">Nome</label>
                          <div className="col-lg-10">
                            <input type="text" className="form-control" id="nome" name="nome" placeholder="Nome do livro" value={book.nome} required/>
                          </div>
                        </div>
                        <div className="form-group">
                          <label for="autor" className="col-lg-2 control-label">Autor</label>
                          <div className="col-lg-10">
                            <input type="text" className="form-control" id="autor" name="autor" placeholder="Autor" value={book.autor}/>
                          </div>
                        </div>
                        <div className="form-group">
                          <label for="editora" className="col-lg-2 control-label">Editora</label>
                          <div className="col-lg-10">
                            <input type="text" className="form-control" id="editora" name="editora" placeholder="Editora" value={book.editora}/>
                          </div>
                        </div>
                        <div className="form-group">
                          <label for="preco" className="col-lg-2 control-label">Preço</label>
                          <div className="col-lg-10">
                            <input type="text" className="form-control" id="preco" name="preco" placeholder="Preço" value={book.preco}/>
                          </div>
                        </div>
                      </fieldset>
                    );
                  })
                }
                <a href="/"><button type="button" className="btn btn-default">Voltar</button></a>
                <button type="submit" className="btn btn-primary">Enviar</button>
              </form>
            </div>
          </div>
        </div>
      </DefaultLayout>
    );
  }
});

module.exports = EditLayout;

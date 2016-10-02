var React = require('react');

var DefaultLayout = require('./default');

var AddLayout = React.createClass({
  render: function() {

    return (
      <DefaultLayout title="react teste">
        <div className="col-md-12">
          <div className="row">
            <div className="well">
              <form method="post" className="form-horizontal" action="/add">
                <fieldset>
                  <legend>Adicionar Livro</legend>
                  <div className="form-group">
                    <label for="nome" className="col-md-2 control-label">Nome</label>
                    <div className="col-md-10">
                      <input type="text" className="form-control" id="nome" name="nome" placeholder="Nome do livro" required/>
                    </div>
                  </div>
                  <div className="form-group">
                    <label for="autor" className="col-md-2 control-label">Autor</label>
                    <div className="col-md-10">
                      <input type="text" className="form-control" id="autor" name="autor" placeholder="Autor" />
                    </div>
                  </div>
                  <div className="form-group">
                    <label for="editora" className="col-md-2 control-label">Editora</label>
                    <div className="col-md-10">
                      <input type="text" className="form-control" id="editora" name="editora" placeholder="Editora" />
                    </div>
                  </div>
                  <div className="form-group">
                    <label for="preco" className="col-md-2 control-label">Preço</label>
                    <div className="col-md-10">
                      <input type="text" className="form-control" id="preco" name="preco" placeholder="Preço" />
                    </div>
                  </div>
                </fieldset>
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

module.exports = AddLayout;

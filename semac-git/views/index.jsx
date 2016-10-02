var React = require('react');

var DefaultLayout = require('./default');

var IndexLayout = React.createClass({

  render: function(){

    return (
      <DefaultLayout title="teste react">
        <div className="col-md-12">
          <div className="row">
            <div className="well">
              <table className="table table-striped table-hover ">
                <thead>
                  <tr>
                    <th>#</th>
                    <th>Nome</th>
                    <th>Autor</th>
                    <th>Editora</th>
                    <th>Preço(R$)</th>
                    <th>Ações</th>
                  </tr>
                </thead>
                <tbody>
                  {
                    this.props.books.map(function(book, i) {

                      return (
                        <tr key={i}>
                          <td>{i+1}</td>
                          <td>{book.nome}</td>
                          <td>{book.autor}</td>
                          <td>{book.editora}</td>
                          <td>{(book.preco).toFixed(2)}</td>
                          <td>
                            <a href={"/edit/" + book._id}><i className="fa fa-pencil" aria-hidden="true"></i></a>
                            <a href={"/view/" + book._id}><i className="fa fa-eye" aria-hidden="true"></i></a>
                            <a href={"/remove/" + book._id}><i className="fa fa-minus" aria-hidden="true"></i></a>
                          </td>
                        </tr>
                      );
                    })
                  }
                </tbody>
              </table>
              <a href="/add"><button type="button" className="btn btn-primary">Adicionar</button></a>
            </div>
          </div>
        </div>
      </DefaultLayout>
    );
  }
});

module.exports = IndexLayout;

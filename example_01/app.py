from flask import Flask, request, render_template_string

app = Flask(__name__)

# Simula um banco de dados simples na memória
database = []

# Template HTML vulnerável para exibir os comentários
HTML_TEMPLATE = """
<!DOCTYPE html>
<html>
<head>
    <title>Avaliações do Produto</title>
</head>
<body>
    <h1>Deixe sua avaliação</h1>
    <form action="/post_comment" method="post">
        Comentário: <br>
        <textarea name="comment" rows="4" cols="50"></textarea>
        <br>
        <input type="submit" value="Enviar">
    </form>
    <hr>
    <h2>Comentários:</h2>
    {% for comment in database %}
        <p>{{ comment | safe }}</p>
    {% endfor %}
</body>
</html>
"""

@app.route('/')
def show_comments():
    return render_template_string(HTML_TEMPLATE, database=database)

@app.route('/post_comment', methods=['POST'])
def post_comment():
    comment = request.form['comment']
    database.append(comment)
    return 'Comentário enviado! <a href="/">Voltar</a>'

if __name__ == '__main__':
    app.run(debug=True)
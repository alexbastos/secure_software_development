#código simplicado

from flask import Flask, request, render_template_string
from markupsafe import escape # Importa a função de sanitização

app = Flask(__name__)

comments = []

@app.route('/post_comment', methods=['POST'])
def post_comment():
    user_name = request.form['name']
    comment_content = request.form['comment']
    
    # Código corrigido: a função escape() sanitiza a entrada
    sanitized_name = escape(user_name)
    sanitized_comment = escape(comment_content)
    
    comments.append(f"<p><strong>{sanitized_name}</strong>: {sanitized_comment}</p>")
    
    return "Comentário postado com sucesso!"

@app.route('/view_comments')
def view_comments():
    comments_html = "".join(comments)
    return render_template_string(f"<h1>Comentários</h1><div>{comments_html}</div>")

if __name__ == '__main__':
    app.run(debug=True)

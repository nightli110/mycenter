
from flask import Flask, render_template, request, make_response
import json

app = Flask(__name__)
app.debug = True


@app.route('/', methods=['POST', 'GET'])
def main():
    return "ok"


@app.route('/hello', methods=['POST'])
def calc():
    data = json.loads(request.get_data(as_text=True))
    print(data)
    return "helloworld"


if __name__ == '__main__':
    app.run()
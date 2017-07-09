# -*- coding: utf-8 -*-
import dash
import dash_core_components as dcc
import dash_html_components as html
import pandas as pd
import plotly.graph_objs as go


df = pd.read_json('http://188.226.164.98:8080/games')

top10df = df.sort_values("score", ascending = False).iloc[0:10]

def generate_table(dataframe, max_rows=10):
    return html.Table(
        # Header
        [html.Tr([html.Th(col) for col in dataframe.columns])] +

        # Body
        [html.Tr([
            html.Td(dataframe.iloc[i][col]) for col in dataframe.columns
        ]) for i in range(min(len(dataframe), max_rows))]
    )


app = dash.Dash()

app.css.append_css({"external_url": "https://codepen.io/chriddyp/pen/bWLwgP.css"})

app.layout = html.Div(children=[
    dcc.Graph(
        figure=go.Figure(
            data=[
                go.Histogram(x=df["score"], nbinsx=10)
                ],
        layout=go.Layout(
            title='Scores distribution',
            showlegend=False,
            margin=go.Margin(l=20, r=0, t=40, b=20)
            

        )
    ),
    style={'height': 300},
    id='my-graph'
    ),

    html.Div(children=[
        html.H4(children='Scores'),
        generate_table(top10df)
    ])
], style={'textAlign': 'center'})

if __name__ == '__main__':
    app.run_server(debug=True)
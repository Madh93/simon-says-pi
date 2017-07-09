FROM python:2.7.12


RUN pip install dash==0.17.7  
RUN pip install dash-renderer==0.7.3
RUN pip install dash-html-components==0.6.2
RUN pip install dash-core-components==0.5.3
RUN pip install plotly==2.0.12
RUN pip install pandas

EXPOSE 8050

ADD webapp.py /

CMD [ "python", "./webapp.py" ]
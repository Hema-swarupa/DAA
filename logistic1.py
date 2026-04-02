import pandas as pd
import numpy as np
def sigmoid(z):
    return 1/(1+np.exp(-z))

data =pd.DataFrame({"exam_score":[35,42,50,60,67,75,80,90,95,100,110,120,130,140,150,160,175,190,210,230],"admitted":[0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1]})
# print(data.head())
# print(data.shape)
# print("Min:", data["exam_score"].min())
# print("Max:", data["exam_score"].max())
# print("Mean:", data["exam_score"].mean())
# print("Std:", data["exam_score"].std())
w=0.0
epochs=1000
b=0.0
n=data.shape[0]
alpha =0.01
x=data["exam_score"].values
y=data["admitted"].values
#print(n)
for i in range(0,1000):
    z=w*x+b
    y_hat=sigmoid(z)
    y_hat=np.clip(y_hat,1e-10,1-1e-10)
    loss = y*np.log(y_hat)+(1-y)*np.log(1-y_hat)
    loss=-(loss.mean())
    grab=y_hat-y
    grab=grab.mean()
    b -=alpha*grab
    gradw=(y_hat-y)*x
    gradw=gradw.mean()
    w -=alpha*gradw
print("final teata0 ",b)
print("final teata1 ",w)
print("final loss ",loss)
y_predicted=sigmoid(w*x+b)
y_predicted=(y_predicted >=0.5).astype(int)
total= (y_predicted == y).mean()
print("accuracy : ",total)
z1=w*65+b
print("prediction ",sigmoid(z1))
z2=w*155+b
print("prediction ",sigmoid(z2))









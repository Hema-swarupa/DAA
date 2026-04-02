import pandas as pd
import numpy as np
def sigmoid(z):
    return 1/(1+np.exp(-z))
data =pd.DataFrame({"exam1":[35,42,50,60,67,75,80,90,95,100,110,120,130,140,150,160,175,190,210,230],
                   "exam2":[40,50,52,65,70,78,85,88,90,92,100,105,110,115,118,120,125,128,130,135],
                   "hours_study":[5,6,7,8,9,10,12,14,15,16,17,18,19,20,22,24,25,26,28,30],"admitted":[0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1]
})

print(data.head(5))
print(data.shape)
print(f"exam1  min:{data["exam1"].min()}   max:{data["exam1"].max()}  mean:{data["exam1"].mean()}   std:{data["exam1"].std()}")
print(f"exam2  min:{data["exam2"].min()}   max:{data["exam2"].max()}  mean:{data["exam2"].mean()}   std:{data["exam2"].std()}")
print(f"hours_study  min:{data["hours_study"].min()}   max:{data["hours_study"].max()}  mean:{data["hours_study"].mean()}   std:{data["hours_study"].std()}")
print(f"admitted  min:{data["admitted"].min()}   max:{data["admitted"].max()}  mean:{data["admitted"].mean()}   std:{data["admitted"].std()}")
means=[data["exam1"].mean(),data["exam2"].mean(),data["hours_study"].mean()]
stds=[data["exam1"].std(),data["exam2"].std(),data["hours_study"].std()]
features =["exam1","exam2","hours_study"]
data[features]=(data[features]-data[features].mean())/data[features].std()
x=data[["exam1","exam2","hours_study"]].values
y=data["admitted"].values.reshape(-1,1)
n=data.shape[0]
theata=np.zeros((4,1))
x=np.c_[np.ones((n,1)) ,x]
alpha =0.01
epochs=1500
for i in range(epochs):
    z=np.dot(x,theata)
    y_hat=sigmoid(z)
    loss=y*np.log(y_hat)+(1-y)*np.log(1-y_hat)
    loss =-(loss.mean())
    gradient =(np.dot(x.T,(y_hat-y)))/n
    theata=theata-alpha*gradient
print("theata vector: ",theata)
print("final loss: ",loss)
y_hat=(y_hat >=0.5).astype(int)
accuracy=(y_hat==y).mean()
print("accuracy: ",accuracy)

x1=(72-means[0])/stds[0]
x2=(80-means[1])/stds[1]
x3=(11-means[2])/stds[2]
xnew=np.array([1,x1,x2,x3]).reshape(-1,4)
znew=np.dot(xnew,theata)
ypre=sigmoid(znew)
print("prediction for a: ",ypre[0][0])
x11=(150-means[0])/stds[0]
x21=(118-means[1])/stds[1]
x31=(20-means[2])/stds[2]
xnew1=np.array([1,x11,x21,x31]).reshape(-1,4)
znew1=np.dot(xnew1,theata)
ypre1=sigmoid(znew1)
print("prediction for b: ",ypre1[0][0])











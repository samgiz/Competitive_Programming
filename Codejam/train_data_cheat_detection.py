# import torch
# import torch.nn as nn
# import pandas as pd
# import numpy as np

# X = np.genfromtxt('x.csv', delimiter=' ')
# y = np.genfromtxt('y.csv', delimiter=' ')


# inputs = torch.from_numpy(X)
# targets = torch.from_numpy(y)

# from torch.utils.data import TensorDataset
# train_ds = TensorDataset(inputs, targets)
# from torch.utils.data import DataLoader
# batch_size = 5
# train_dl = DataLoader(train_ds, batch_size, shuffle=True)

# model = nn.Linear(3, 2)
# import torch.nn.functional as F

# loss_fn = F.mse_loss
# opt = torch.optim.SGD(model.parameters(), lr=1e-5)

from __future__ import absolute_import, division, print_function
import tensorflow.compat.v1 as tf
tf.disable_v2_behavior() 

import pandas as pd	

import numpy as np



# num_classes = 2

# model = tf.keras.models.Sequential([
#   tf.keras.layers.Dense(1, activation='sigmoid')
# ])
# # import matplotlib.pyplot as plt 

# # Parameters 
# learning_rate = 0.01 
# training_epochs = 25 
# batch_size = 100 
# display_step = 1 

# num_params = 5
# # tf Graph Input 
# x = tf.placeholder("float", [None, num_params]) # mnist data image of shape 28*28 = 784 
# y = tf.placeholder("float", [None, 1]) # 0-9 digits recognition => 10 classes 

# # Create model 
# # Set model weights 
# W = tf.Variable(tf.zeros([num_params, 1])) 
# b = tf.Variable(tf.zeros([1]))

# # Construct model 
# activation = tf.nn.sigmoid(tf.matmul(x, W) + b) 

# # Minimize error using cross entropy 
# cross_entropy = y*tf.log(activation) 
# cost = tf.reduce_mean(-tf.reduce_sum(cross_entropy,reduction_indices = 1)) 

# optimizer = tf.train.GradientDescentOptimizer(learning_rate).minimize(cost) 

# #Plot settings 
# avg_set = [] 
# epoch_set = [] 

# # Initializing the variables init = tf.initialize_all_variables()
# # Launch the graph 
# with tf.Session() as sess:
#    sess.run(init)
   
#    # Training cycle
#    for epoch in range(training_epochs):
#       avg_cost = 0.
#       total_batch = int(mnist.train.num_examples/batch_size)
      
#       # Loop over all batches
#       for i in range(total_batch):
#          batch_xs, batch_ys = mnist.train.next_batch(batch_size)
#          # Fit training using batch data sess.run(optimizer, \ feed_dict = {
#             x: batch_xs, y: batch_ys}) 
#          # Compute average loss avg_cost += sess.run(cost, \ feed_dict = {
#             x: batch_xs, y: batch_ys})/total_batch
#       # Display logs per epoch step
#       if epoch % display_step == 0:
#          print ("Epoch:", '%04d' % (epoch+1), "cost=", "{:.9f}".format(avg_cost))
#             avg_set.append(avg_cost) epoch_set.append(epoch+1)
#    print ("Training phase finished")
    
# #    plt.plot(epoch_set,avg_set, 'o', label = 'Logistic Regression Training phase') 
# #    plt.ylabel('cost') 
# #    plt.xlabel('epoch') 
# #    plt.legend() 
# #    plt.show() 
    
#    # Test model 
#    correct_prediction = tf.equal(tf.argmax(activation, 1), tf.argmax(y, 1)) 
   
#    # Calculate accuracy 
#    accuracy = tf.reduce_mean(tf.cast(correct_prediction, "float")) print 
#       ("Model accuracy:", accuracy.eval({x: mnist.test.images, y: mnist.test.labels}))

import seaborn as sns
import matplotlib.pyplot as plt
# corr = data.corr()

# stack = np.hstack((X, [[i] for i in y]))
# sns.set_theme()
# corr = np.corrcoef(stack, rowvar = False)
# sns.heatmap(corr)

# plt.show()

iterations = 200
learn_rate = 0.6
W = tf.Variable(tf.zeros([5,1], dtype = tf.float32), name='W')
b = tf.Variable(tf.zeros([1], dtype = tf.float32), name='b')
X = tf.placeholder(tf.float32, [None, 5], name='X')
y = tf.placeholder(tf.float32, [None], name='y')
X_data = np.genfromtxt('x.csv', delimiter=' ')
y_data = np.genfromtxt('y.csv', delimiter=' ')

X_data[:, 0] /= 10000
X_data[:, 1] /= 1000000
X_data[:, 2] /= 1000000
X_data[:, 3] /= 10000
X_data[:, 4] /= 10000

model = tf.add(tf.matmul(X, W), b)

cost = tf.reduce_mean(tf.square(y - model))
train = tf.train.GradientDescentOptimizer(learn_rate).minimize(cost)

init = tf.global_variables_initializer()



with tf.Session() as session:
    session.run(init)

    for _ in range(iterations):
        print(_)
        session.run(train, feed_dict={
            X: X_data,
            y: y_data
        })

    print("cost = {}".format(session.run(cost, feed_dict={
        X: X_data,
        y: y_data
    })))
    print("W = {}".format(session.run(W)))
    print("b = {}".format(session.run(b)))
getfile imagelist labellist

np.random.shuffle()

getbatch()
输入：imagelist labellist, 图片宽 图片高 batchsize
返回image_batch (4dtensor, [batch_size, w, h, 3] 和label_batch [batch_size

tf.cast

input_queue = tf.train.slice_input_producer(imagelist, labellist)

reader: tf.read_file
decoder: tf.image.decode_jepg()

tf.image.resize_image_with_crop_or_pad()

tf.image.per_image_standardzation()

tf.train.batch()


weights : weights = tf.get_variable(name, shape=[kernel size, kernel size, input_channel, out_channel], 
initializer = tf.truncatedr_normal_initilizer())

bias = tf.get_variable(name, shape = [n], initializer = tf.constant_initilizaer(0.1)

conv = tf.nn.conv2d(image, weights, strides = [1,1,1,1], padding = ‘SAME’)

activation = tf.nn.bias_add(conv, bias)
conv1 = tf.nn.relu(activation);

pool = tf.max_pool(tensor, ksize=[1,3,3,1], stride = [1,1,1,1],padding = ‘SAME’)


loss(logits, label)

tf.nn.sparse_softmax_cross_entropy_with_logits

tf.summary.scalar() tensorboard;

optimizer = tf.train.Adamoptimizer(learning_rate)
tf..nn_in_top_k(logits, labels)


summary_op = tf.summary.merge_all()

train_writer = tf.summary.FileWriter(logs, sess.graph)


saver = tf.train.saver()
saver.save(checkpoint)

ckpt = tf.train.get_checkpoint_state(logs)
saver.restore(ckpt)

vgg16.npy python保存的一堆数字

data_dict = np.load(vgg16.npy).item()

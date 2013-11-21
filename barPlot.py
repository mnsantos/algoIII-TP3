import pylab as p
import sys
import os
import glob

os.chdir("ejecutables/")


fig = p.figure()
ax = fig.add_subplot(1,1,1)
y = [4, 6, 7, 3]
N = len(y)
ind = range(N)
p.ylim([0,8])
ax.bar(ind, y, facecolor='#777777',
       align='center', ecolor='black')
ax.set_ylabel('Frontera')
ax.set_title('CMF para cada algoritmo',fontstyle='italic')
ax.set_xticks(ind)
group_labels = ['Exacto', 'Goloso', 'B. Local', 'Tabu']
ax.set_xticklabels(group_labels)
fig.autofmt_xdate()
p.show()

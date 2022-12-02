#-*- coding:utf-8 -*-
# import os
# import urllib.parse

# from instagramy import InstagramHashTag

# session_id = os.environ.get("SESSION_ID")

# i = 0
# name_arr = ['개포동', '이상화', '사과']
# result_arr = []

# f = open('test.txt', 'w')

# for i in name_arr:
# 	name = urllib.parse.quote(i)
# 	tag = InstagramHashTag(name, sessionid=session_id, from_cache=True)
# 	f.write('{0} : '.format(i))
# 	f.write('{0}\n'.format(str(tag.number_of_posts)))

# f.close


# 시간 출력 부분
# import time

# print(time.strftime('%x %X', time.localtime(time.time())))
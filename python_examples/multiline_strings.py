from __future__ import print_function

'''String literals'''
a = 'This is ' \
   'just a string spanning over two lines.'

# '\' is required
b = 'Another string ' \
   ' spanning over two lines.'

c = '''More pythonic string 
spanning over several lines. Also 
as used in doc comments.'''

print(a, b, c)


'''dict initialization'''
#builtin_types = [type(int), type(string), type(character), type(byte)]
#builtin_types = [type(int), type(char), type(byte)]
builtin_types = [type(int)]
compound_types = [type(object)]
boxed_types = [type(tuple), type(list), type(dict), type(set)]
categories = {'builtin': [builtin_types],
              'compound': [compound_types],
              'boxed': [boxed_types]}

print(categories.keys())

# while True:
#     num = input("Input:")
#     if num[0] == '-':
#         num = num[1:]
#     num_len = len(num)
#     bits = [0] * 10
    
#     for i in range(num_len):
#         bits[int(num[i])] += 1
            
#     for i in range(10):
#         if bits[i] > 0:
#             print("{}: {}".format(i, bits[i]))
#     print("total: {} bits".format(num_len))
    
#     choice = input("continue?")
#     if choice.lower() == 'no':
#         break
    
# while True:
#     num = input("Input:")
#     if num[0] == '-':
#         num = num[1:]
#     num_len = len(num)
#     num_dict = {}
    
#     for i in range(num_len):
#         if num[i] in num_dict:
#             num_dict[num[i]] += 1
#         else:
#             num_dict[num[i]] = 1
            
#     for key, value in num_dict.items():
#         print("{}: {}".format(key, value))
#     print("total: {} bits".format(num_len))
    
#     choice = input("continue?")
#     if choice.lower() == 'no':
#         break

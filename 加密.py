import hashlib

def passwd(password):
    hash = hashlib.md5()
    hash.update(password.encode('utf-8'))
    return hash.hexdigest()
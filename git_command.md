# 关联用户和邮箱
git config --global user.name "your name"
git config --global user.email "email@163.com"

# 初始化
git init

# 查看文件状态
git status

# 添加管理文件
git add file && git add . 

# 提交版本文件
git commit -m "v1"

# 查看提交文件所在分支
git log

# 回滚
git reset --hard 版本号

# 查看回滚前的版本号,再执行回滚
git reflog && git reset --mix 版本号

# 已修改文件还原
git checkout -- file

# 暂存区文件还原到工作区
git reset HEAD file

# 查看分支
git branch 

# 添加分支
git branch new_site

# 切换分支
git checkout new_site

# 合并分支
git merge new_site

# 删除分支
git branch -d new_site

# 给远程仓库起别名
git remote add origin https://.git

# 推送代码
git push -u origin 分支

# 克隆远程仓库代码
git clone 远程仓库
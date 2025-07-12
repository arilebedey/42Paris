return {
  "MoulatiMehdi/42norm.nvim",
  ft = { "c", "cpp" },
  config = function()
    if vim.loop.os_uname().sysname == "Darwin" then
      local venv_path = "/Users/ari/.venv/norminette-venv/bin"
      vim.env.PATH = venv_path .. ":" .. vim.env.PATH
    end

    local norm = require("42norm")

    norm.setup({
      header_on_save = true,   -- Insert/update 42 header on save
      format_on_save = true,   -- Format code on save
      linter_on_change = true, -- Update diagnostics when buffer changes
      timeout = 4000,          -- Timeout for norminette (in milliseconds)
    })
  end,
}

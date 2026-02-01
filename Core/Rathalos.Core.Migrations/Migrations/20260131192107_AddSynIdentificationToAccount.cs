using Microsoft.EntityFrameworkCore.Migrations;

#nullable disable

namespace Rathalos.Core.Migrations.Migrations
{
    /// <inheritdoc />
    public partial class AddSynIdentificationToAccount : Migration
    {
        /// <inheritdoc />
        protected override void Up(MigrationBuilder migrationBuilder)
        {
            migrationBuilder.AddColumn<char[]>(
                name: "SynIdent",
                table: "accounts",
                type: "character(1)[]",
                nullable: true);
        }

        /// <inheritdoc />
        protected override void Down(MigrationBuilder migrationBuilder)
        {
            migrationBuilder.DropColumn(
                name: "SynIdent",
                table: "accounts");
        }
    }
}
